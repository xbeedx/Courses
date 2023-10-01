import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    rows = db.execute("SELECT * FROM Stocks WHERE buyer_id = ?", session["user_id"])
    cash = db.execute("SELECT cash FROM users where id=?",session["user_id"])[0]["cash"]
    total=0
    for row in rows:
        total += (row["price"]*row["quantity"])
    total+=cash
    return render_template("index.html", rows=rows, cash=usd(cash), total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
        if not request.form.get("shares"):
            return apology("must provide shares", 403)

        x = lookup(request.form.get("symbol"))
        if x == None:
            return apology("symbol invalid", 403)

        cash_available = db.execute("SELECT cash FROM users where id=?",session["user_id"])[0]["cash"]
        if x["price"] > float(cash_available):
            return apology("not enough cash", 403)

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_available-x["price"] ,session["user_id"])
        db.execute("INSERT INTO Stocks (quantity,price,name,buyer_id,stock) VALUES (?,?,?,?,?)", request.form.get("shares"), x["price"],x["name"] ,session["user_id"], x["name"])

        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
         if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
         x = lookup(request.form.get("symbol"))
         if x == None:
              return apology("symbol invalid", 403)
         return render_template("quoted.html", name = x["name"], symbol = x["symbol"] ,cost= usd(x["price"]) )
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password matches
        elif not request.form.get("confirmation"):
            return apology("confirm the password", 403)

        elif request.form.get("confirmation") != request.form.get("password"):
            return apology("passwords don't match", 403)

        else:
            db.execute("INSERT INTO users (username,hash) VALUES (?,?)", request.form.get("username"), generate_password_hash(request.form.get("password")))
            rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
            session["user_id"] = rows[0]["id"]
            return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)
        if not request.form.get("shares"):
            return apology("must provide shares", 403)

        x = lookup(request.form.get("symbol"))
        if x == None:
            return apology("symbol invalid", 403)

        cash_available = db.execute("SELECT cash FROM users where id=?",session["user_id"])[0]["cash"]

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_available + (float(x["price"])*float(request.form.get("shares"))) ,session["user_id"])
        db.execute("DELETE FROM Stocks WHERE quantity = ? AND Stock = ? AND buyer_id = ?", request.form.get("shares"), request.form.get("symbol") ,session["user_id"],)

        return redirect("/")
    else:
        rows = db.execute("SELECT * FROM Stocks WHERE buyer_id = ?", session["user_id"])
        return render_template("sell.html", rows = rows)
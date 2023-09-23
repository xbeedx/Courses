from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET","POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html",name=request.form.get("name","world"))

# @app.route("/greet", methods=["POST"])
# def greet():
#     return render_template("greet.html",name=request.args.get("name","world"))
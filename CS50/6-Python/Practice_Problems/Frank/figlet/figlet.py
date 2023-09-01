import sys
import random
from pyfiglet import Figlet

figlet = Figlet()
fonts = figlet.getFonts()

if len(sys.argv) == 1:
    font_input = random.choice(fonts)

elif len(sys.argv) == 3:
    if(sys.argv[1] != "-f" and sys.argv[1] != "--font"):
        sys.exit("Usage: figlet.py -f/--font font")

    font_input = sys.argv[2]
    if font_input not in fonts:
        sys.exit("Invalid font")

else:
    sys.exit("Usage: figlet.py args...")

text = input("Text: ")
figlet.setFont(font=font_input)
print(figlet.renderText(text))
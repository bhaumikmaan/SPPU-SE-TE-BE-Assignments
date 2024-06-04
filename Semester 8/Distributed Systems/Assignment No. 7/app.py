from flask import Flask, render_template, request
import requests
import json

app = Flask(__name__)


@app.route("/")
def home():
   return render_template("index.html")


@app.route("/calculate", methods=["POST"])
def calculate():
   num1 = int(request.form["num1"])
   num2 = int(request.form["num2"])
   operation = request.form["operation"]

   payload = {"num1": num1, "num2": num2}

   if operation == "add":
       url = "http://localhost:5000/add"
   elif operation == "subtract":
       url = "http://localhost:5000/subtract"
   elif operation == "multiply":
       url = "http://localhost:5000/multiply"
   elif operation == "divide":
       url = "http://localhost:5000/divide"

   response = requests.post(url, json=payload)
   result = json.loads(response.text)

   return render_template("result.html", result=result)


if __name__ == "__main__":
   app.run(debug=True, port=3000)

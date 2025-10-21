from datetime import datetime
import os
import sqlite3

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup

# Configure application
app = Flask(__name__)


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///final_project.db")


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

    return render_template("home.html")


@app.route("/congrats")
@login_required
def congrats():

    return render_template("congrats.html")


@app.route("/question1")
@login_required
def question1():
    """ show qustion1 """

    return render_template("question1.html")


@app.route("/question2")
@login_required
def question2():
    """ show qustion3 """

    return render_template("question2.html")

@app.route("/question3")
@login_required
def question3():
    """ show qustion3 """

    return render_template("question3.html")

@app.route("/question4")
@login_required
def question4():
    """ show qustion4 """

    return render_template("question4.html")

@app.route("/question5")
@login_required
def question5():
    """ show qustion5 """

    return render_template("question5.html")

@app.route("/question6")
@login_required
def question6():
    """ show qustion6 """

    return render_template("question6.html")

@app.route("/question7")
@login_required
def question7():
    """ show qustion7 """

    return render_template("question7.html")

@app.route("/question8")
@login_required
def question8():
    """ show qustion8 """

    return render_template("question8.html")

@app.route("/question9")
@login_required
def question9():
    """ show qustion9 """

    return render_template("question9.html")

@app.route("/question10")
@login_required
def question10():
    """ show qustion10 """

    return render_template("question10.html")

@app.route("/question11")
@login_required
def question11():
    """ show qustion11 """

    return render_template("question11.html")

@app.route("/question12")
@login_required
def question12():
    """ show qustion12 """

    return render_template("question12.html")

@app.route("/question13")
@login_required
def question13():
    """ show qustion13 """

    return render_template("question13.html")

@app.route("/question14")
@login_required
def question14():
    """ show qustion14 """

    return render_template("question14.html")

@app.route("/question15")
@login_required
def question15():
    """ show qustion15 """

    return render_template("question15.html")


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
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
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


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # return apology("TODO")
    session.clear()

    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password(again) was submitted
        if not request.form.get("confirmation"):
            return apology("must provide confirmation", 400)

        # Ensure password and password(again) match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username does not already exist
        if len(rows) != 0:
            return apology("username already exist", 400)

        # Insert new user into database
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)",
                   request.form.get("username"), generate_password_hash(request.form.get("password")))

        # Query db for newly inserted user
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else:
        return render_template("registration.html")


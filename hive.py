from flask import Flask, jsonify, render_template, request
import subprocess
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/honey', methods=['POST'])
def honey():
    inFile = open('nectar.txt')
    p = subprocess.Popen(['./honeybee', '-r', 'cnn.com', '-n', '10'], stdin=inFile, stdout=subprocess.PIPE)
    out, err = p.communicate()
    return jsonify(data=str(out, 'utf-8').split('\n')[1:])

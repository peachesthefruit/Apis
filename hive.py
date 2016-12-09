from flask import Flask, jsonify, render_template, request
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/honey', methods=['POST'])
def honey():
    data = []
    f = open('out.txt', 'r')
    for line in f:
        line = line.rstrip()
        data.append('www.' + line)
    return jsonify(data=data)

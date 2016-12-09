from flask import Flask, jsonify, render_template, request
import subprocess
import urlparse
import json
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/honey', methods=['POST'])
def honey():
    url = request.get_data().split('=')[-1]
    #url = urlparse(url).netloc.strip('w')
    inFile = open('./nectar.txt')
    p = subprocess.Popen(['./honeybee', '-b', url, '-n', '1'], stdin=inFile, stdout=subprocess.PIPE)
    out, err = p.communicate()
    return jsonify(data=out.split('\n')[1:-1])

#!/usr/bin/env python3.5

from flask import Flask, jsonify, render_template, request
import subprocess
from urllib.parse import urlparse, unquote
import json
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/honey', methods=['POST'])
def honey():
    data = request.get_data().decode(encoding='UTF-8')
    url = urlparse(unquote(data.split('=')[-1]))
    site = url.netloc or url.path
    site = site.replace('www.','')

    inFile = open('./nectar.txt')
    
    p = subprocess.Popen(['./honeybee', '-b', site, '-n', '1'], stdin=inFile, stdout=subprocess.PIPE)
    out, err = p.communicate()
    out = out.decode(encoding='UTF-8')
    data = out.split('\n')[1:-1]

    return jsonify(data=data)

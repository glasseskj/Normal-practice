# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

from pwn import * # pip install pwntools
import json

r = remote('socket.cryptohack.org', 13377, level = '100')

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)


def Hex(text):
    return bytearray.fromhex(text).decode()
    
import codecs
def rot13(text):
    re=codecs.encode(text, 'rot_13')
    return re

import base64
def base_64(text):
    a = text.encode("UTF-8")
    b = base64.b64decode(a)
    re = b.decode("UTF-8")
    return re
    
def bigint(text):
    return bytearray.fromhex(text[2:]).decode()

def utf8(text):
    return ''.join(chr(i) for i in text)

received = json_recv()


tt=0
while "type" in received.keys() and tt<150:
    print("\n\ntt = "+str(tt))
    print("Received type: ")
    print(received["type"])
    print("Received encoded value: ")
    print(received["encoded"])
    send=""
    if received["type"] == "hex":
        send = Hex(received["encoded"])
        
    if received["type"] == "rot13":
        send = rot13(received["encoded"])
        
    if received["type"] == "base64":
        send = base_64(received["encoded"])
        
    if received["type"] == "bigint":
        send = bigint(received["encoded"])
        
    if received["type"] == "utf-8":
        send = utf8(received["encoded"])
        
    to_send = {
    "decoded": send
    }
    json_send(to_send)
    received = json_recv()
    print("\n"+str(received))
    tt=tt+1
    
print(received)


## from https://cryptohack.org/challenges/general/
"""
Now you've got the hang of the various encodings you'll be encountering, let's have a look at automating it.

Can you pass all 100 levels to get the flag?

The 13377.py file attached below is the source code for what's running on the server. The pwntools_example.py file provides the start of a solution using the incredibly convenient pwntools library. which you can use if you like. pwntools however is incompatible with Windows, so telnetlib_example.py is also provided.

For more information about connecting to interactive challenges, see the FAQ. Feel free to skip ahead to the cryptography if you aren't in the mood for a coding challenge!

Connect at nc socket.cryptohack.org 13377
"""




    
    
    

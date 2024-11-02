import json
import time
import keyauth
from keyauth import api
import tkinter
from tkinter import *
from tkinter import filedialog
from tkinter import messagebox
import os
import hashlib
from time import sleep
from datetime import datetime
import sys
import subprocess
import psutil

correct = False

def getchecksum():
    md5_hash = hashlib.md5()
    file = open(''.join(sys.argv), "rb")
    md5_hash.update(file.read())
    digest = md5_hash.hexdigest()
    return digest

keyauthapp = api(
    name = "FULLPACK_SO",
    ownerid = "hzWzcmKeZS",
    secret = "3f93382f1606df878041278f0b10dd7c1adfacba4169a9c4a6e356e6ac0c25ac",
    version = "1.4",
    hash_to_check = getchecksum()
)

global file_path

def eac_off():
    try:
        with open(f'{file_path.get()}/game/x64/EasyAntiCheat/Settings.json'.replace("/", "\\")) as json_file:
            data = json.load(json_file)
            try:
                data["productid"] = data["productid"].replace("5","1")
            except:
                try:
                    data["productid"] = data["productid"].replace("e","f")
                except:
                    data["productid"] = data["productid"].replace("f","c")
            try:
                data["sandboxid"] = data["sandboxid"].replace("5","1")
            
            except:
                try:
                    data["sandboxid"] = data["sandboxid"].replace("e","f")
                except:
                    data["sandboxid"] = data["sandboxid"].replace("f","c")
            try:
                data["deploymentid"] = data["deploymentid"].replace("5","1")
            except:
                try:
                    data["deploymentid"] = data["deploymentid"].replace("e","f")
                except:
                    data["deploymentid"] = data["deploymentid"].replace("7","c")
        with open(f'{file_path.get()}/game/x64/EasyAntiCheat/Settings.json'.replace("/", "\\"), 'w') as f:
            json.dump(data, f, ensure_ascii=False, indent=4)
        messagebox.showinfo("True", "EAC is disabled\nPress OK to start game and cheat")
        subprocess.call([f"{file_path.get()}/game/x64/start_protected_game.exe"])
        sys.exit(1)
    except Exception as e:
        lbox.insert(END, "Error path")
        lbox.yview(END)
        messagebox.showerror("Error path", "Path is not correct")

        
def browseFiles(): 
    filename = filedialog.askdirectory(parent=app,initialdir="/",title='Выберите папку с игре StalkerOnline')
    file_path.set(filename)
    with open("path.txt", 'w+') as file:
        file.write(str(filename))
    temp_menu = 0

try:      
    with open("key.txt", 'r') as file:
        text_key = file.read()
except:
    messagebox.showerror("Error key", "Can't find file key.txt\n Please login in ayus-cheat.exe")
    sys.exit(1)
    
print("Ключ: " + text_key)
if (len(text_key) == 0):
    messagebox.showerror("Error key", "Can't find key\n Please login in ayus-cheat.exe")
    sys.exit(1)

keyauthapp.license(text_key)



for proc in psutil.process_iter():
    name = proc.name()
    if name == "sogame.exe":
        sys.exit(1)


app = tkinter.Tk()
app.title("AYUS Manager")
app.geometry('350x600+500+100')
try:
    app.iconbitmap('app.ico')
except:
    messagebox.showerror("Error icon", "Can't find app.ico")

file_path = StringVar()
file_path.set('Выберите папку с игрой')
try:
    with open('path.txt', 'r') as file:
        file_path.set(file.read())
    
    if (len(file_path) > 0):
        eac_off()    
except:
    pass
file_text = Entry(textvariable=file_path)
file_text.configure(state='disabled')
file_text.place(x=16, y=135, height=25, width=170)
file_button = Button(text='Обзор', command=browseFiles)
file_button.place(x=189, y=135, height=25)
file_button2 = Button(text='Подтвердить', command=eac_off)
file_button2.place(x=239, y=135, height=25)

lbox = Listbox(app, width=55, height=20, selectmode=EXTENDED)
lbox.place(x=10, y=245)

lbox.insert(END, "Ключ правильный")
lbox.yview(END)
    
app.mainloop()


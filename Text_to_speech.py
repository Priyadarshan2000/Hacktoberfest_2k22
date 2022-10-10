from tkinter import *
from gtts import gTTS
from playsound import playsound

root=Tk()
root.geometry('350x300')
root.configure(bg="ghost white")
root.title("Rambo-- TEXT TO SPEECH")

Label(root,text="TEXT TO SPEECH",font="arial 20 bold",bg='white smoke').pack()
Label(root,text="Rambo Plays",font="arial 15 bold",bg='white smoke',width='20').pack(side='bottom')

msg=StringVar()
Label(root,text="Enter text",font="arial 15 bold",bg='white smoke').place(x=20,y=60)

entry_field=Entry(root,textvariable=msg,width='50')
entry_field.place(x=20,y=100)


def Text_to_speech():
    message=entry_field.get()
    speech=gTTS(text=message)
    speech.save('phoenix.mp3')
    playsound('phoenix.mp3')

def Exit():
    root.destroy()

def Reset():
    msg.set("")

Button(root,text="PLAY",font='arial 15 bold',command=Text_to_speech,width='4').place(x=25,y=140)
Button(root,text="EXIT",font='arial 15 bold',command=Text_to_speech,width='4',bg='OrangeRed1').place(x=100,y=140)
Button(root,text="RESET",font='arial 15 bold',command=Text_to_speech,width='6').place(x=175,y=140)

root.mainloop()

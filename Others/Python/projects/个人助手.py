
import speech

assistent_name = "Lucy"

while True:
    speech.say("你真厉害")
    phrase = speech.input()
    if phrase == "你好":
        speech.say("It's me.")
    else:
        speech.say("sorry")
    break

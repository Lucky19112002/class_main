import json
from difflib import get_close_matches

data = json.load(open("data.json"))


def translate(w):
    w = w.lower()
    if w in data:
        return data[w]
    elif len(get_close_matches(w, data.keys())) > 0:
        yesno = input("Did you mean %s instead? Enter y if yes, or n if no: " % get_close_matches(w, data.keys())[0])
        if yesno == "Y" or "y" or "yes" or "Yes":
            return data[get_close_matches(w, data.keys())[0]]
        elif yesno == "N" or "n" or "No" or "no":
            return "The word doesn't matched. Please double check your input"
        else:
            return "we didn't understand your input"
    else:
        return "The word doesn't exist. Please double check your input"


word = input("Enter your word: ")
output = translate(word)
if type(output) == list:
    for item in output:
        print(item)
else:
    print(output)
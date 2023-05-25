
import random

greeting=['Hello there !','Ariose mego','hello. how you doing?']
help=['How may I help you','What can i do for you']
bye=['bye','nice chatting with you']

def chatbot():
    print('chatbot : '+ 'welcome ')
    while True:
        user_in=input('user:')
        if 'hey'in user_in.lower() or 'hello' in user_in.lower():
            print(random.choice(greeting))
        if 'bye' in user_in.lower():
            print(random.choice(bye))
            break
        


chatbot()

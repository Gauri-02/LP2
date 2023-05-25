def rule1(symptons):
    if "fever" in symptons and "cough" in symptons and "headache" in symptons:
        return "You have flu"

def rule2(symptons):
    if "dizziness" in symptons and "nausea" in symptons and "weakness" in symptons:
        return "you may have low iron content"
    
def getDia(symptons):
    rules=[rule1,rule2]
    results=[]
    for rule in rules:
        result=rule(symptons)
        if result:
            results.append(result)
    if len(results)==0:
        return "sorry we couldnt dia"
    else: return results
    




def diagonsis():
    symp=input("Symptons: ")
    symptons=symp.lower().split(" ")
    result=getDia(symptons)
    print(result)
   

diagonsis()
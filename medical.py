

def rule1(symptons):
    if 'fever' in symptons and 'cough' in symptons and 'fatigue' in symptons:
        return 'You may have flu'
    return None

def rule2(symptons):
    if 'headache' in symptons and 'dizziness' in symptons :
        return 'You might have low iron content'
    return None


def get_diagonsis(symptons):
    rules=[rule1,rule2]
    results=[]
    for rule in rules:
        result=rule(symptons)
        if result :
            results.append(result)
    if len(results) ==0 :
        return 'Sorry very limited data for diagonsis'
    else :return results
    
    

def diagonsis():
    input_sym=input("symptons : ")
    symptons=input_sym.lower().split(" ")
    print("hjdsj")
    result=get_diagonsis(symptons)
    print(result)

diagonsis()

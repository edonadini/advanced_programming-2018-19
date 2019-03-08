
def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    ########################
    l = list(string_var)
    m = len(l) 
    for i in range(m/2):
         if l[i]!=l[m-i-1]:
            return False
    return True    
    ########################
    return ret 

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''
    ########################
    l = list(string_var)
    dic = {}
    for i in l:
        if i in dic:
            dic[i]=dic[i] +1
        else:
            dic[i]=1
    return dic    
    ########################

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    '''
    ########################
    l = list(list_var)
    dic = histogram_letters(l)
    ret = sorted(dic.items(), key=lambda value: value[1])[-1]   
    return ret
    ########################

from collections import Counter
def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    ########################
    l=list(list_var)
    dic = {k:v for k, v in Counter(l).items() if v > 1}
    return dic
    ########################

def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    ########################
    if (numero == 0 or numero==1):
        return 1
    return numero*compute_factorial(numero-1)    
    ########################


def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    ########################
    if (numero==1):
        return False
    if (numero== 2):
        return True
    for i in  range(2,numero//2):
        if (numero%i==0):
            return False
            break
    return True    
    ########################

        


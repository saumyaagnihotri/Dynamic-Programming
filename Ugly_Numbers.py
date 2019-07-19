#Ugly Numbers = numbers are numbers whose only prime factors are 2, 3 or 5

def solve(n):
    ugly = [0]*n
    ugly[0] = 1
    two = three = five = 0
    next_two = 2; next_three = 3; next_five = 5
    for l in range(1,n):
        ugly[l] = min(next_two,next_three,next_five)
        if ugly[l]==next_two:
            two+=1
            next_two=ugly[two]*2
        if ugly[l]==next_three:
            three+=1
            next_three=ugly[three]*3
        if ugly[l]==next_five:
            five+=1
            next_five=ugly[five]*5
    return ugly[-1]

n = int(input())
print(solve(n))
            
        
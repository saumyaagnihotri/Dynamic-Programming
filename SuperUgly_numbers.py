#Ugly Numbers = numbers are numbers whose only prime factors are 2, 3 or 5

def solve(n,k):
    ugly = [0]*n
    ugly[0] = 1
    multiple_of = [0 for i in range(len(k)+1)]
    next_multiple = [i for i in k]
    for l in range(1,n):
        ugly[l] = min([i for i in next_multiple])
        for i in range(len(k)):
            if(next_multiple[i]==ugly[l]):
                multiple_of[i]+=1
                next_multiple[i] = k[i]*(ugly[multiple_of[i]])
                break
    return ugly[-1]

k = list(map(int,input().split()))
n = int(input())
print(solve(n,k))
            
        

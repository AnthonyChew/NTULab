# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    count = 0

    for i in range(len(arr) - 1):
        
        # n-1 != index
        if(arr[i] - 1 != i):

            for j in range(i + 1 , len(arr) ):
                print(arr[j], arr[i] )
                if(arr[j] == i + 1):
                    if(i == 0):
                        arr[j] , arr[i] = arr[i] , arr[j]
                    count += 1
                    break
    
    return count


arr = [2, 3, 4, 1, 5]

my = minimumSwaps(arr)
print(my)

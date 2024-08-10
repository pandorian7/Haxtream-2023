weight = int(input())
n = int(input())

weights = list(map(int, input().split()))
sorted_weights = [i for i in weights]
sorted_weights.sort()
sorted_weights = sorted_weights[::-1]

indexes = []

for i in sorted_weights:
    if weight >= i:
        weight -= i
        index = weights.index(i)
        indexes.append(index)
        weights[index] = weight+1

for i in sorted_weights[::-1]:
    if (weight > 0):
        weight -= i
        index = weights.index(i)
        indexes.append(index)
        weights[index] = weight+1


indexes.sort()
print(" ".join(map(str, indexes)))

n = int(input())
heights = list(map(int, input().split()))

changes = []
for i in range(n-1):
    a = heights[i]
    b = heights[i+1]
    form = ""
    if a < b:
        form = "hill"
    if a > b:
        form = "slope"
    if a == b:
        form = "flat"

    changes.append(form)

changes.append(None)
state = None
start = 0
end = 0

for i, s in enumerate(changes):
    if (s != state):
        end = i
        if (state):
            print(f"{start}-{end}={state}")
        start = i
        state = s

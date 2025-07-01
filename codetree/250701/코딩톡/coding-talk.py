n, m, p = map(int, input().split())
messages = [tuple(input().split()) for _ in range(m)]
c = [msg[0] for msg in messages]
u = [int(msg[1]) for msg in messages]

# Please write your code here.
all_members = set([chr(i) for i in range(ord('A'), ord('A')+n)])
read_msg = set(c[p-1:])
if u[p-1] == 0:
    print()
else:
    print(*sorted(list(all_members - read_msg)))


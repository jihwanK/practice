cnt = 0
 
def recur(mem, count, maxv):
  global cnt
   
  if count == 0:
    cnt += 1
    cur_str = ''.join(mem)
    # print(cnt, cur_str)
    if int(maxv) < int(cur_str):
      maxv = cur_str
    return maxv
   
  for i in range(len(mem)):
    for j in range(i + 1, len(mem)):
      tmp = mem[i]
      mem[i] = mem[j]
      mem[j] = tmp
 
      maxv = recur(mem, count-1, maxv)
 
      tmp = mem[i]
      mem[i] = mem[j]
      mem[j] = tmp
   
  return maxv
  
# test_case = input()
# for T in range(test_case):
#   st, count = input().split()
#   count = int(count)
#   ans = recur(list(st), count, st)
#   print('#{} {}'.format(T + 1, ans))

rfile = open('input.txt', 'r')
lines = rfile.readlines()

test_case = lines[0]
for T in range(1, len(lines)):
  st, count = lines[T].split()
  count = int(count)
  ans = recur(list(st), count, st)
  print('#{} {}'.format(T + 1, ans))
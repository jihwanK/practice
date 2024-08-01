def solution(name):
    answer = 0
    init = ["A"]*len(name)
    name = list(name)

    to_fix= [i for i in range(len(name)) if init[i] != name[i]]

    cur = 0
    while init != name:
        print(to_fix, cur, abs(cur - to_fix[0]), abs(cur + (len(name)-to_fix[-1]))%len(name))
        if abs(cur - to_fix[0]) > abs(cur + (len(name)-to_fix[-1]))%len(name):
            answer += abs(cur+(len(name)-to_fix[-1]))%len(name) 
            cur = to_fix[-1]
            to_fix = to_fix[:-1]
        else:
            answer += abs(cur-to_fix[0])
            cur = to_fix[0]
            to_fix = to_fix[1:]

        i, n = ord(init[cur]), ord(name[cur])
        diff = n - i
        if diff >= 13:
            answer += (26 - diff)
            init[cur] = chr(ord("Z") - (25-diff))
            print(answer, cur, "diff >= 13", 25-diff)
        else:
            answer += diff
            init[cur] = chr(ord(init[cur]) + diff)
            print(answer, cur, "diff < 13", diff)


        print(init)
        print()

    return answer

if __name__ == "__main__":
    # print(solution("JEROEN"))
    # print(solution("JAN"))
    # print(solution("AAAAAAAAABBBBB")) #10
    # print(solution("ABBAAABAAAABB")) #15
    # print(solution("BAABBAAA")) #7
    # print(solution("AABAAABAA")) #8
    # print(solution("BBBABAABABABB")) #20
    print(solution("BBABAAAAAAB")) #9
    # print(solution("BABBAABB")) #11
    # print(solution("BBAAAAAAABAB")) #9
    # print(solution("BAABBAAA")) #7


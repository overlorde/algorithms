class solution:
    def sum(self,arr1,arr2):
        lst = []
        x = ""
        for n in reversed(arr1):
            x = x + str(n)
        y = ""
        for n in reversed(arr2):
            y = y + str(n)

        ans = int(x) + int(y)
        ans_ext = str(ans)

        for i in ans_ext:
            lst.append(int(i))

        return lst


x = solution()
y = x.sum([2,4,3],[5,6,4])
print(y)

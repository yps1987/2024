class Solution(object):
    @staticmethod
    def part1(list1, list2):
        total = 0
        list1.sort()
        list2.sort()
        for i, j in zip(list1, list2):
            total += abs(i - j)
        return total

    @staticmethod
    def part2(list1, list2):
        hashtable = {}
        total = 0
        for elem in list2:
            if elem in hashtable:
                hashtable[elem] += 1
            else:
                hashtable[elem] = 1

        for elem in list1:
            total += (elem * hashtable.get(elem, 0))
        return total


def main() -> None:
    # importare date
    list1 = []
    list2 = []
    with open("./1/input.txt", "r") as file:
        data = file.read()
        lines = data.splitlines()
        for line in lines:
            numbers = line.split()
            if len(numbers) == 2:
                list1.append(int(numbers[0]))
                list2.append(int(numbers[1]))

    sol = Solution()
    print("PART1 AoC DAY 1:", sol.part1(list1, list2))
    print("PART2 AoC DAY 1:", sol.part2(list1, list2))

if __name__ == "__main__":
    main()
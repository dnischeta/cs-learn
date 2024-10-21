class  NumberStats:
    def __init__(self):
        self.numbers = 0
        self.sum = 0

    def add_number(self, number:int):
        self.numbers = self.numbers + 1
        self.sum = self.sum + number

    def count_numbers(self):
        return self.numbers

    def get_sum(self):
        return self.sum

    def average(self):
        return self.sum/self.numbers

stats = NumberStats()
stats.add_number(3)
stats.add_number(5)
stats.add_number(1)
stats.add_number(2)
print("Numbers added:", stats.count_numbers())
print("Sum of numbers:", stats.get_sum())
print("Mean of numbers:", stats.average())

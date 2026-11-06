class TwoSum:
    def __init__(self):
        self.stored = []
    def add(self, number: int) -> None:
        self.stored.append(number)
    def find(self, value: int) -> bool:
        seen = set()
        for num in self.stored:
            if value - num in seen:
                return True
            seen.add(num)
        return False

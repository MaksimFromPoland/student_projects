class Counter:
    def __init__(self, start=0, stop=None):
        self.count = start
        self.max = stop


    def get(self):
        return self.count

    def increment(self):
        if self.max is not None and self.count >= self.max:
            print('Maximal value is reached.')
        else: self.count += 1


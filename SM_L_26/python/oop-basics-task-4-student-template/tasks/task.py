class HistoryDict:
    def __init__(self, dic):
        self.dic = {}

    def set_value(self, key, value):
        self.dic[key] = value

    def get_history(self):
        result = []
        for key in self.dic:
            result.append(key)

        return result


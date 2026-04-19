class Pagination:
    def __init__(self, data, items_on_page):
        self.text = [data[i:i+items_on_page] for i in range(0, len(data), items_on_page)]
        self.items_on_page = items_on_page
        self.item_count = len(data)

    @property
    def page_count(self):
        return len(self.text)

    def count_items_on_page(self, page_number):
        if page_number < self.page_count - 1:
            return self.items_on_page
        elif page_number == self.page_count - 1:
            return len(self.text[self.page_count - 1])
        elif page_number < 0 or page_number > self.page_count - 1:
            raise Exception("Invalid index. Page is missing.")

    def find_page(self, data):
        result = []

        for i in range(len(self.text)):
            if data in self.text[i]:
                result.append(i)
                continue

            if i < len(self.text) - 1:
                combined = self.text[i] + self.text[i + 1]

                if data in combined and data not in self.text[i] and data not in self.text[i + 1]:
                    result.append(i)
                    result.append(i + 1)

        result = sorted(set(result))

        if not result:
            raise Exception(f"'{data}' is missing on the pages")

        return result
    
    def display_page(self, page_number):
        if page_number < 0 or page_number > self.page_count - 1:
            raise Exception("Invalid index. Page is missing.")
        return self.text[page_number]





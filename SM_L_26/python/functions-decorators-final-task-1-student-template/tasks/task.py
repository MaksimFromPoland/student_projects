from typing import List


def split(data: str, sep=None, maxsplit=-1) -> List[str]:
    result = []

    if maxsplit == 0:
        return [data]

    if sep is None:
        data = data.strip()
        if not data:
            return []

        current_word = []
        splits_done = 0

        for char in data:
            if char.isspace():
                if current_word:
                    if maxsplit != -1 and splits_done >= maxsplit:
                        idx = data.index(''.join(current_word))
                        remainder = ''.join(current_word) + data[idx + len(''.join(current_word)):]
                        result.append(remainder)
                        return result

                    result.append(''.join(current_word))
                    current_word = []
                    splits_done += 1
            else:
                current_word.append(char)

        if current_word:
            result.append(''.join(current_word))
    else:
        current_part = []
        splits_done = 0
        i = 0
        sep_len = len(sep)

        while i < len(data):
            if maxsplit != -1 and splits_done >= maxsplit:
                result.append(''.join(current_part) + data[i:])
                return result

            if data[i:i + sep_len] == sep:
                result.append(''.join(current_part))
                current_part = []
                splits_done += 1
                i += sep_len
            else:
                current_part.append(data[i])
                i += 1

        result.append(''.join(current_part))

    return result

if __name__ == '__main__':
    assert split('') == []
    assert split(',123,', sep=',') == ['', '123', '']
    assert split('test') == ['test']
    assert split('Python    2     3', maxsplit=1) == ['Python', '2     3']
    assert split('    test     6    7', maxsplit=1) == ['test', '6    7']
    assert split('    Hi     8    9', maxsplit=0) == ['Hi     8    9']
    assert split('    set   3     4') == ['set', '3', '4']
    assert split('set;:23', sep=';:', maxsplit=0) == ['set;:23']
    assert split('set;:;:23', sep=';:', maxsplit=2) == ['set', '', '23']
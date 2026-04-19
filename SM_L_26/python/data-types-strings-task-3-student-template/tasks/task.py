def replacer(s: str) -> str:
    result = ""
    for i in s:
        if i == "'":
            result += '"'
        elif i == '"':
            result += "'"
        else:
            result += i

    return result

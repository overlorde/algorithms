def average(L):
    if not L:
        return None

    return sum(L)/len(L)
"""
if __name__ == "__main__":
    L = [1,2,3,4,5]
    print(average(L))
"""

def test_average():
    assert 3.0 == average([1,2,3,4,5])

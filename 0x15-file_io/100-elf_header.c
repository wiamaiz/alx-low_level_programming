def remove_duplicates(lst1, lst2):
    """Returns a new list that contains only the unique elements from lst1 and lst2"""
    unique_elements = []
    for item in lst1:
        if item not in unique_elements:
            unique_elements.append(item)
    for item in lst2:
        if item not in unique_elements:
            unique_elements.append(item)
    return unique_elements

# Example usage
list1 = [1, 2, 3, 4]
list2 = [3, 4, 5, 6]
result = remove_duplicates(list1, list2)
print(result)


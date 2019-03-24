chem = input().strip()

for w in chem:
    if '1' <= w <= '9':
        compound, digits = chem.split(str(w))
        digits = ''.join([w, digits])

# num_of_compund = 0
# for ch in compound:
#     if 'A' <= ch <='Z':
#         num_of_compund += 1

print(compound)
print(digits)

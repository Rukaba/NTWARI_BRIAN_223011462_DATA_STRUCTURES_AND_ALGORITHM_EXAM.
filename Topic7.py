def insertion_sort(records):
    for i in range(1, len(records)):
        key = records[i]
        j = i - 1
        while j >= 0 and records[j]['priority'] > key['priority']:
            records[j + 1] = records[j]
            j -= 1
        records[j + 1] = key

# Example Usage
records = [
    {'patient_id': 1, 'name': "John Doe", 'priority': 2},
    {'patient_id': 2, 'name': "Jane Smith", 'priority': 1},
    {'patient_id': 3, 'name': "Alex Brown", 'priority': 3}
]

insertion_sort(records)
for record in records:
    print(f"Patient ID: {record['patient_id']}, Name: {record['name']}, Priority: {record['priority']}")

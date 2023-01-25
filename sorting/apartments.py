n, m, k = list(map(int, input().split()))
applicants = list(map(int, input().split()))
apartments = list(map(int, input().split()))
applicants.sort()
apartments.sort()

i = j = 0
ans = 0
while i < len(applicants) and j < len(apartments):
  if abs(applicants[i] - apartments[j]) > k and applicants[i] > apartments[j]:
    j += 1
  elif abs(applicants[i] - apartments[j]) > k and applicants[i] < apartments[j]:
    i += 1
  else:
    i += 1
    j += 1
    ans += 1
print(ans)
  

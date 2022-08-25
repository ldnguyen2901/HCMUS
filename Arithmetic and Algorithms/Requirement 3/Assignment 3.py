def euclid_algorithm(u, v):
  u1, u2, u3 = 1, 0, u
  v1, v2, v3 = 0, 1, v

  while v3 != 0:
    q = u3 // v3
    t1, t2, t3 = u1 - q*v1, u2 - q*v2, u3 - q*v3
    u1, u2, u3 = v1, v2, v3
    v1, v2, v3= t1, t2, t3

  return u1, u2, u3

u = 42
v = 56
print(euclid_algorithm(u, v))


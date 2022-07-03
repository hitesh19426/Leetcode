Mistake 1: Remove values/parameters for removed Key, not original key
​
Mistake 2: forgot to remove bucket from buckets map after bucket got empty in moveKey
​
Mistake 3: When invalidating key, remove key when cache is full, if it is then remove and then insert.  Inserting first and then invalidating is wrong.
​
Mistake 4: what if cap = 0
​
​
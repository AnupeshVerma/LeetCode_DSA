SELECT 
    *,
    IF(LEFT(dna_sequence, 3) = 'ATG', 1, 0) AS has_start,
    IF(RIGHT(dna_sequence, 3) IN ('TAA', 'TAG', 'TGA'), 1, 0) AS has_stop,
    IF(dna_sequence LIKE '%ATAT%', 1, 0) AS has_atat,
    IF(dna_sequence LIKE '%GGG%', 1, 0) AS has_ggg
FROM Samples
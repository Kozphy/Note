#mssql 

## The benefit of storing index on columnStone
- Faster Scans
- Faster Aggregations
- Faster Joins
- Higher Compression
- Types of **Columnstore** indexes
	- **Clustered Columnstore Index (CCI)**: Primary storage for table data, replacing the rowstore heap or clustered index.
	- **Nonclustered Columnstore Index (NCCI)**: Additional index on top of the rowstore heap or clustered index.

In summary, **Columnstore** indexes are designed for data warehousing scenarios with large tables storing historical or aggregated data
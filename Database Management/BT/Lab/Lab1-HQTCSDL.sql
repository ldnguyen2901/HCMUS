--exam1
if DB_ID('Northwind') is not null 
begin
select 'database does exit'
end
else
begin
select 'database does not exit'
end


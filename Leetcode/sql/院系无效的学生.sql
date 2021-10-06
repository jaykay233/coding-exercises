SELECT
	s.id,
	s.name
FROM
	Students AS s
	LEFT OUTER JOIN Departments AS d
		ON s.department_id =  d.id
where d.id is null

 
#insert graph instance
Insert Into graph (graphID, graph, graphType) 
Values('d41d8cd98f00b204e9800998ecf8427e', '', 'JPG');

#insert user_graph instance
Insert Into user_graph (userID, graphID)
Values(1, 'd41d8cd98f00b204e9800998ecf8427e')
On Duplicate Key 
Update graphID = 'd41d8cd98f00b204e9800998ecf8427e';

#get graph instance
Select graph.graphID, graphType, graph
From graph, user_graph
Where graph.graphID = user_graph.graphID 
	and user_graph.userID = 1
Limit 1;


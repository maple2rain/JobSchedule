#insert gif instance
Insert Into gif (gifName) 
Values('name');

#update gif instance
Insert Into user_gif (userID, gifID) 
Values(1, 2)
On Duplicate Key 
Update gifID = 1;

#get gif instance
Select gif.gifID, gifName 
From gif, user_gif
Where gif.gifID = user_gif.gifID and user_gif.userID = 1
Limit 1;

#get gifID instance
Select gifID 
From gif 
where gifName = 'name';

using BoreD.Services;

var client = new BoredService();

var activity = await client.GetActivity();

Console.WriteLine($"Activity: {activity.Activity}");
Console.WriteLine($"Type: {activity.Type}");
Console.WriteLine($"Participants: {activity.Participants}");
Console.WriteLine($"Estimated Price: ${activity.Price} USD");
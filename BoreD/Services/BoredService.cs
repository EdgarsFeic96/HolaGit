using BoreD.Models;
using Newtonsoft.Json;

namespace BoreD.Services;

public class BoredService : IBoredService
{
    public static readonly HttpClient _httpClient = new();
    public static readonly string _url = "https://www.boredapi.com/api/activity/";

    public async Task<BoredResponse> GetActivity()
    {
        var response = await _httpClient.GetAsync(_url);
        var content = await response.Content.ReadAsStringAsync();
        return JsonConvert.DeserializeObject<BoredResponse>(content)!;
    }
}
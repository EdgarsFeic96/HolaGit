using BoreD.Models;
using Newtonsoft.Json;

namespace BoreD.Services;

/// <summary>
/// Servicio para obtener la información de la API.
/// </summary>
public class BoredService : IBoredService
{
    public static readonly HttpClient _httpClient = new()
    {
        BaseAddress = new Uri("https://www.boredapi.com/api/")
    };

    public async Task<BoredResponse> GetActivity()
    {
        var response = await _httpClient.GetAsync("activity/");
        var content = await response.Content.ReadAsStringAsync();
        return JsonConvert.DeserializeObject<BoredResponse>(content)!;
    }
}
using Newtonsoft.Json;

namespace BoreD.Models;

#nullable disable

/// <summary>
/// Modelo de una respuesta de The Bored API
/// necesaria para deserializar el JSON obtenido
/// en un objeto de C#.
/// </summary>

public class BoredResponse
{
    [JsonProperty("activity")]
    public string Activity { get; set; }

    [JsonProperty("type")]
    public string Type { get; set; }

    [JsonProperty("participants")]
    public long Participants { get; set; }

    [JsonProperty("price")]
    public double Price { get; set; }

    [JsonProperty("link")]
    public string Link { get; set; }

    [JsonProperty("key")]
    public long Key { get; set; }

    [JsonProperty("accessibility")]
    public double Accessibility { get; set; }
}

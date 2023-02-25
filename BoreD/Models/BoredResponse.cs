using Newtonsoft.Json;

namespace BoreD.Models;

#nullable disable

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

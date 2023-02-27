using BoreD.Models;

namespace BoreD.Services;

/// <summary>
/// Contiene los métodos necesarios para obtener la información desde la API.
/// </summary>
public interface IBoredService
{
    /// <summary>
    /// Obtiene una actividad aleatoria desde 
    /// <see href="https://www.boredapi.com">The Bored API</see>.
    /// </summary>
    /// <returns>Objeto <see cref="BoredResponse"></see>
    /// con la respuesta obtenida de la API</returns>
    public Task<BoredResponse> GetActivity();
}

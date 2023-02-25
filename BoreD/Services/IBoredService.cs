using BoreD.Models;

namespace BoreD.Services;

public interface IBoredService
{
    public Task<BoredResponse> GetActivity();
}

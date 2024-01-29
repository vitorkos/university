
using Microsoft.EntityFrameworkCore;
//using handson.Data;
// using Api.Auth;
using Microsoft.OpenApi.Models;
// using Microsoft.AspNetCore.Authentication.JwtBearer;
// using Microsoft.IdentityModel.Tokens;
using System.Text;
using Api.Data;

namespace Api;



public class Program
{
    public static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);
        // Add services to the container.

        // Add inje��o de depend�ncia do Auth token service
        // builder.Services.AddScoped<AuthService>();
        // builder.Services.AddScoped<CryptService>();

        // builder.Services.AddAuthentication(x =>
        // {
        //     x.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme;
        //     x.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme;
        // }).AddJwtBearer(options =>
        // {
        //     options.RequireHttpsMetadata = false;
        //     options.SaveToken = true;
        //     options.TokenValidationParameters = new TokenValidationParameters
        //     {
        //         ValidateIssuerSigningKey = true,
        //         IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(Configuration.PrivateKey)),
        //         ValidateIssuer = false,
        //         ValidateAudience = false,
        //     };
        // });

        builder.Services.AddControllers();

        // Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
        builder.Services.AddEndpointsApiExplorer();

    //     builder.Services.AddSwaggerGen(c =>
    //     {
    //         c.SwaggerDoc("v1", new OpenApiInfo { Title = "Your API", Version = "v1" });

    //         // Adicione a configura��o do Bearer Token
    //         c.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme
    //         {
    //             Description = "JWT Authorization header using the Bearer scheme.",
    //             Type = SecuritySchemeType.Http,
    //             Scheme = "bearer"
    //         });

    //         // Adicione a configura��o do Bearer Token no cabe�alho da requisi��o
    //         c.AddSecurityRequirement(new OpenApiSecurityRequirement
    // {
    //     {
    //         new OpenApiSecurityScheme
    //         {
    //             Reference = new OpenApiReference
    //             {
    //                 Type = ReferenceType.SecurityScheme,
    //                 Id = "Bearer"
    //             }
    //         },
    //         new string[] { }
    //     }
    // });
    //     });

    //     builder.Services.AddSwaggerGen();

        builder.Services.AddDbContext<ApiDbContext>(options =>
            options.UseSqlite(builder.Configuration.GetConnectionString("SqliteConnectionString")));

        var app = builder.Build();

        // Configure the HTTP request pipeline.
        // if (app.Environment.IsDevelopment())
        // {
        //     app.UseSwagger();
        //     app.UseSwaggerUI(c =>
        //     {
        //         c.SwaggerEndpoint("/swagger/v1/swagger.json", "Your API V1");
        //         c.InjectStylesheet("/swagger-ui/custom.css"); // Opcional: personalizar o estilo
        //         c.InjectJavascript("/swagger-ui/custom.js");   // Opcional: personalizar o comportamento
        //     });
        // }

        app.UseHttpsRedirection();

        // app.UseAuthentication();
        // app.UseAuthorization();
        

        app.MapControllers();

        app.Run();
    }
}

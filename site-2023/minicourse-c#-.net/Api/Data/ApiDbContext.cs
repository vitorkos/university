using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Api.Models;


namespace Api.Data
{
    public class ApiDbContext : DbContext{

        public ApiDbContext(DbContextOptions<ApiDbContext> options) : base(options)
        {
        }

        public DbSet<Category> Categories{get;set;}

        public DbSet<ToDo> ToDos{get;set;}

        public DbSet<User> Users{get; set;}
    }
}